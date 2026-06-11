#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    int i;
    for(i=0;i<m;i++){
        cin >> a.at(i);
        n -= a.at(i);
    }

    if(n >= 0){
        cout << n << endl;
    }else{
        cout << -1 << endl;
    }
}