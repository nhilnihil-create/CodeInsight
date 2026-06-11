#include<iostream>
#include<string>
using namespace std;

int main(){
    //input
    string S;
    cin >> S;
    long long keta=S.length();
    long long N[keta];
    long long i;
    for(i=0; i<keta; i++){
        N[i]=(long long)(S[i]-'0');
    }

    //calc
    long long cho=0, kuri=100;
    long long cho_copy, kuri_copy;
    for(i=keta-1; i>=0; i--){
        cho_copy=cho;
        kuri_copy=kuri;
        cho = min(cho_copy+N[i],kuri_copy+1+N[i]);
        kuri = min(cho_copy+(10-N[i]),kuri_copy+(9-N[i]));
    }

    //answer
    cout << min(cho,kuri+1) << endl;
    system("pause");
    return 0;
}