#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
   
    int K,N,maxv;
    cin >> K >> N;
    int data[N];
    
    for(int i=0;i<N;i++) cin >> data[i];
    
    for(int i=0;i<N;i++){
        if(i==0) maxv = data[i+1] - data[i];
        else if(i!= N-1 && maxv < data[i+1] - data[i]) maxv = data[i+1] - data[i];
        else if(i == N-1 && ((K-data[i]) + data[0]) > maxv) maxv = K - data[i] + data[0];
    }
    
    cout << K - maxv << endl;
}