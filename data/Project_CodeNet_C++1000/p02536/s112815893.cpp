#include<bits/stdc++.h>
using namespace std;

int root(int x, vector<int> &city){
    if(city.at(x) == x){
        return x;
    }
    else{
        return city.at(x) = root(city.at(x), city);
    }
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> city(n);
    vector<int> rank(n);
    vector<int> unionCity(n);
    for(int i = 0;i < n;i++){
        city.at(i) = i;
        rank.at(i) = 0;
        unionCity.at(i) = 0;
    }

    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        int x = city.at(a-1);
        int y = city.at(b-1);
        int rtx = root(x, city);
        int rty = root(y, city);
        if(rtx != rty){
            if(rank[rtx] < rank[rty]){
                city.at(rtx) = rty;
            }
            else{
                city.at(rty) = rtx;
            }
            if(rank.at(rtx) == rank.at(rty)){
                rank.at(rtx)++;
            }

        }
    }

    for(int i = 0;i < n;i++){
        int rt = root(i, city);
        if(unionCity.at(rt) == 0){
            unionCity.at(rt)++;
        }
    }
    int sum = 0;

    for(int i = 0;i < n;i++){
        sum += unionCity.at(i);
    }
    cout << sum - 1 << endl;

}