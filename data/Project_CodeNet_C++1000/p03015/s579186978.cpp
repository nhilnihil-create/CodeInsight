#include<iostream>
#include<string>
using namespace std;

long long MOD=1000000007;

int main(){
    //input
    string S;
    cin >> S;
    long long keta=S.length();
    long long L[keta];
    long long i;
    for(i=0; i<keta; i++){
        L[i]=(long long)(S[i]-'0');
    }

    //calc
    long long bdd, nonbdd;
    nonbdd=1;
    bdd=2;
    for(i=1; i<keta; i++){
        if(L[i]==0){
            nonbdd = 3*nonbdd;
            nonbdd%=MOD; 
        }else if(L[i]==1){
            nonbdd = 3*nonbdd + bdd;
            nonbdd%=MOD;
            bdd = 2*bdd;
            bdd%=MOD;
        }
    }

    //answer
    cout << (nonbdd + bdd)%MOD << endl;
    system("pause");
    return 0;
}