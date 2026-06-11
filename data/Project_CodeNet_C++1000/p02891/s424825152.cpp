#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<utility>
#include<cstdio>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include <bitset>
using namespace std;
const int mod=1e9+7;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n;i++)
#define rep2(i,x,n) for (int i= x;i<n;i++)
#define all(v) v.begin(), v.end()
#define nepe(v) next_permutation(all(v))
#define F first 
#define S second
#define PB push_back 
#define MP make_pair
using ll = long long;
using vi = vector<int>; 
using vvi = vector<vi>;
using vl=vector<long long>;
using vvl = vector<vl>;
using vp =vector<pair<int,int>>;

typedef pair<int,int> P;
string s;
int k;
ll INF = 1000000000000;

int main(){
    string S;
    cin >>S;
    ll N =S.size();
    ll K;
    cin >>K;
    int tempc=0,cc=0;
    if(S[0]==S[N-1]){
        char mark =S[0];
        ll lc=0,rc=0;
        rep(i,N-1){
            if(S[i]==mark) lc++;
            else break;
        }
        rep(i,N-1){
            if(S[N-1-i]==mark)  rc++;
            else break;
        }
        if(lc+rc==2*(N-1)) cout <<N*K/2<<endl;
        else{
            rep2(i,lc,N-rc-1){
                if(S[i]==S[i+1]) tempc ++;
                else{
                    cc += max(0,(tempc+1)/2);
                    tempc =0;
                }
            }
            cc += max(0,(tempc+1)/2);
            cout <<lc/2+rc/2+cc*K+((lc+rc)/2)*(K-1)<<endl;
        }
    }
    else{
        rep(i,N-1){
            if(S[i]==S[i+1]) tempc ++;
            else{
                cc +=max(0,(tempc+1)/2);
                tempc =0;
            }   
        }
        cc += max(0,(tempc+1)/2);
        cout <<cc*K<<endl;
    }
}
