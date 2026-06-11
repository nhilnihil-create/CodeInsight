#include <bits/stdc++.h>
using namespace std ;
typedef long long ll;
 
int main(){
    int N;cin>>N;
    int a[N],b[N];
    for(int i=0;i<N;i++) cin>>a[i];
    for(int i=0;i<N;i++) b[i]=a[i];
    
    sort(a,a+N);
    for(int i=0;i<N;i++){
        if(b[i]==a[N-1]) cout << a[N-2] <<endl;
        else cout << a[N-1] <<endl;
    }
      
}