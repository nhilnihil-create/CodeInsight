#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Check(int *p,int N,int *start,int target){
    
    for(int i=(*start);i<N;i++){ if(*(p+i) == target){*start = i+1; return true;} }
    return false;
}
int main(){

    int N,ans=0;
    cin >> N;
    int data[N];
    for(int i=0;i<N;i++) cin >> data[i];
    
    int key = 1,start_position=0;
    while(1){
        if(Check(&data[0],N,&start_position,key)){ ans++; key++; }
        else {break;}
    }
    if(ans == 0) cout << -1 << endl;
    else cout << N - ans << endl;
    
}