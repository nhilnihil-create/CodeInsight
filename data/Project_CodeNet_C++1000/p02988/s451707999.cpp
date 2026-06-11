#include <bits/stdc++.h>
using namespace std;
bool Check(int a,int b,int c){
    
    if(a > c){
        
        if(a > b && b > c) return true;
        else return false;
    }
    else{
        if(a < b && b < c) return true;
        else return false;
    }
}
int main(void){
    
    int N,ans=0;
    cin >> N;
    int data[N];
    
    for(int i=0;i<N;i++) cin >> data[i];
    
    for(int i=0;i<N-3+1;i++) if(Check(data[i],data[i+1],data[i+2])) ans++;
    cout << ans << endl;
}