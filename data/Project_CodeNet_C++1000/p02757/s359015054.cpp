#include<bits/stdc++.h>
using namespace std;

long long int c[10005];
int main(){
    string S;
    long long int N,P,i;
    long long int tmp = 0;
    long long int count = 0;
    long long int ten=1;
    cin >> N >> P;
    cin >> S;
    if(P==2 || P==5){
        for(i=0;i<S.length();i++)if((S[i]-'0')%P==0)count+=(i+1);
    }
    else{
        for(i=0;i<S.length();i++){
            tmp=tmp+ten*(S[N-1-i]-'0');
            tmp%=P;
            ten=(ten*10)%P;
            c[tmp]++;
        }
        count=c[0];
        for(i=0;i<P;i++)count+=c[i]*(c[i]-1)/2;
    }
    cout << count << endl;
}