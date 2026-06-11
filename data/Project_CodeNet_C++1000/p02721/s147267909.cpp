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
    int N, K, C;
    string S;
    cin >> N >> K >> C >> S;

    vector<int> L(K+1,0);
    vector<int> R(K+1,N+1);
    int cnt=0;
    int vac=0;
    for(int i=0; i<N; i++){
        if(vac>0){
            vac--;
        }else if(S[i]=='o'){
            cnt++;
            L[cnt]=i+1;
            vac=C;
        }
        if(cnt==K)break;
    }

    cnt=K;
    vac=0;
    for(int i=N-1; i>=0; i--){
        if(vac>0){
            vac--;
        }else if(S[i]=='o'){
            R[cnt]=i+1;
            vac=C;
            cnt--;
        }
        if(cnt==0)break;
    }

    //cout_vec(L);
    //cout_vec(R);

    for(int i=1; i<=K; i++){
        if(L[i]==R[i]){
            cout << L[i] << '\n';
        }
    }
}