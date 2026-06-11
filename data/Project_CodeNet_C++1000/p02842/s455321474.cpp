#include <bits/stdc++.h>
using namespace std;
double s;
long long n;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>n;
for(int i = 1;i <= 50000; i++){
         s = i*1.08;
        int q=(int)s;
        if(n==q){
            cout<<i<<endl;
            return 0;
        }
    }
    cout << ":(" << endl;
return 0;}

