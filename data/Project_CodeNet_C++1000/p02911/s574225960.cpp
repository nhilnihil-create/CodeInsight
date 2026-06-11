#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int n, k, q, tmp;
    cin >> n >> k >> q;
    vector<long long> a(n, k - q);
    for(int i = 0; i < q; i++){
        cin >> tmp;
        a[tmp-1]++;
    }
    for(int i = 0;  i < n; i++){
        if(a[i]>0){
            cout << "Yes" <<endl;
        }else{
            cout <<"No"<<endl;
        }
    }
}