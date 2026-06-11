#include <bits/stdc++.h>
using namespace std ;
int main(){
    int N,X;
    cin >> N >> X;
    int L[N];
    for(int i=0;i<N;i++)cin >> L[i];
    int NP=0;
    int count =1;
    for(int i=0;i<N;i++){
        NP+=L[i];
        if(NP<=X)count++;
        else break;
    }
    cout << count << endl;
}
