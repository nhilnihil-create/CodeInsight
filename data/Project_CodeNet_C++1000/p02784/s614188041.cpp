#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int H, N;
    cin >> H >> N;
    int sum=0;
    for(int i = 0; i<N; i++){
        int x;
        cin >> x;
        sum +=x;
    }
    
    if(sum >= H){
        cout<<"Yes"<<endl;
    }else if(H > sum){
        cout<< "No" <<endl;
    }
    
}