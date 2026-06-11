#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

template<typename T>
void cout_vec(vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    for(auto &a:A){
        cin >> a;
    }
    for(auto &b:B){
        cin >> b;
    }

    int b=0;
    vector<int> achieved(N,0);
    int cnt=0;
    ll ans=0;
    int tmp=0;
    while(cnt<N){
        if(tmp==N){
            cout << -1 << endl;
            return 0;
        }
        int a=(N+b-1)%N;
        int c=(N+b+1)%N;
        //cout << a << ' ' << b << ' ' << c << ' ' << tmp << endl;
        if(achieved[b]==0 && B[b]==A[b]){
            achieved[b]=1;
            cnt++;
            b=(b+1)%N;
            continue;
        }else if(B[b]<A[b]){
            cout << -1 << endl;
            return 0;
        }

        if(B[b]>B[a]+B[c]){
            if((B[b]-A[b])%(B[a]+B[c])==0){
                ans+=(ll)(B[b]-A[b])/(B[a]+B[c]);
                B[b]=A[b];
            }else{
                ans+=(ll)B[b]/(B[a]+B[c]);
                B[b]%=(B[a]+B[c]);
            }
            tmp=0;
        }else{
            tmp++;
        }
        b=(b+1)%N;
        //cout << ans << endl;
        //cout_vec(B);
    }
    cout << ans << endl;
}