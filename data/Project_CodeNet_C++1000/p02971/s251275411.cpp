#include <bits/stdc++.h>
using namespace std;
#define INF 1e9+7
typedef long long int ll;
const int maxn = 1000000;
ll mod = INF;


int main(){
    
    int n;
    int a[maxn];
    cin >> n;
    for(int i=0;i<n;i++)cin >> a[i];
    int M1=0, M2=0;
    for(int i=0;i<n;i++){
        if(a[i]>=M1){
            M2=M1;
            M1=a[i];
        }else if(a[i]>=M2){
            M2=a[i];
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==M1){
            cout << M2<<endl;
        }else{
            cout << M1<<endl;
        }
    }
    return 0;
}