#include <bits/stdc++.h>
using namespace std;

vector<int> vector_plus(vector<int> &arr1,vector<int> &arr2,int &m){
    vector<int> result(m+1);
    for(int i=0;i<m+1;i++){
        result.at(i) = arr1.at(i) + arr2.at(i);
    }
    return result;
}

bool x_check(vector<int> arr,int x,int m){
    bool flag = true;
    for(int i=1;i<m+1;i++){
        if(arr.at(i) < x){
            flag = false;
            break;
        }
    }
    return flag;
}

int main(){
    int n,m,x;
    cin >> n >> m >> x;
    vector<vector<int>> array(n,vector<int>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m+1;j++){
            cin >> array.at(i).at(j);
        }
    }
    vector<int> money(0);
    for(int tmp = 0; tmp < ( 1 << 12); tmp++){
        bitset<12> s(tmp);
        vector<int> arr(m+1);
        for(int i=0;i<n;i++){
            if(s.test(i)){
                arr = vector_plus(arr,array.at(i),m);
            }
        }
        //for(int j=0;j<arr.size();j++) cout << arr.at(j) << " ";
        //cout << endl;
    if(x_check(arr,x,m)){
        money.push_back(arr.at(0));
    }
    }
    //for(int i=0;i<money.size();i++) cout << money.at(i) << endl;
    if(money.size() < 1){
        cout << -1 << endl;
    }else{
        int min = 2147483647 ;
        for(int i=0;i<money.size();i++){
            if(min > money.at(i)){
                min = money.at(i);
            }
        }
        cout << min << endl;
    }

}

