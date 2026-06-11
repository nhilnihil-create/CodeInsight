#include <bits/stdc++.h>
using namespace std;
int My_Abs(int data[],int t,int n){
    
    int r=0,l=0;
    for(int i = 0;i<t;i++) l+= data[i];
    for(int i = t;i<n;i++) r+= data[i];
    return abs(r-l);
}
int main(void){
   
    int N,ans = 0;
    cin >> N;
    int data[N];
    
    for(int i=0;i<N;i++) cin >> data[i];
    
    for(int t=0;t<N;t++){
        if(t == 1) ans = My_Abs(data,t,N);
        else{
            int v = My_Abs(data,t,N);
            if(ans > v) ans = v;
        }
    }
    cout << ans << endl;
}