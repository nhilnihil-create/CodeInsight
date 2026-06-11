#include <bits/stdc++.h>
using namespace std;

int main(void){

    int N,nmax = 0,last = 0;
    cin >> N;
    int data[N];
    for(int i=0;i<N;i++) cin >> data[i];
    
    for(int i=1;i<N;i++){
        if(data[i-1] >= data[i]){
            nmax++;
        }
        else{
            if(nmax >= last){
                last = nmax;
                nmax = 0;
            }
            else{
                nmax = 0;
            }
        }
    }
    cout << max(nmax,last) << endl;
}
