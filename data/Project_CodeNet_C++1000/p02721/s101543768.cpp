#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,K,C;
    string str;
    cin >> N >> K >> C >> str;
    int L[K],R[K];
    int n=0;
    for(int i=0; i<K; i++){
        while(str.at(n)!='o'){
            n++;
        }
        L[i]=n;
        n+=C+1;
    }
    n=N-1;
    for(int i=K-1; i>=0; i--){
        while(str.at(n)!='o'){
            n--;
        }
        R[i]=n;
        n-=C+1;
    }
    for(int i=0; i<K; i++){
        if(L[i]==R[i]){
            cout << L[i]+1 << endl;
        }
    }
    return 0;
}
