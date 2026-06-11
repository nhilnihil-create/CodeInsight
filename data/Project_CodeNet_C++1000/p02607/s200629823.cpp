#include <bits/stdc++.h>
using namespace std ;
#define An setprecision(16) 
int main(){
    int N;
    cin >> N;
    int a[N+1];
    int count =0;
    for(int i=1;i<=N;i++){
        cin >> a[i];
        if(i%2==1){
            if(a[i]%2==1)count++;
        }
    }
    cout << count << endl;
}