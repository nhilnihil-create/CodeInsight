#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,count = 0;
    cin >> n;
    vector<int> data(n);
    pair<int,int> a;
    pair<int,int> b;
    for (int i = 0; i < n; i++){
        cin >> data.at(i);
    }
    for (int i = 0; i < n-1; i++){
        if(data.at(i) > data.at(i+1)){
            if(count == 0){
                a.first = i;
                a.second = data.at(i);
                count ++;
            }else if(count == 1){
                b.first = i+1;
                b.second = data.at(i+1);
                count ++;
            }
        }
    }
    swap(data.at(a.first),data.at(b.first));
    for (int i = 0; i < n-1; i++){
        if(data.at(i) > data.at(i+1)){
            cout << "NO" << endl;
            return 0;
        }
    }

        cout << "YES" << endl;
}