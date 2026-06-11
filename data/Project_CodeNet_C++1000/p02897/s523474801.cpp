#include<bits/stdc++.h>
using namespace std;

#define lld long long
#define pi pair<int,int>
#define pl pair<lld,lld>
#define mem0(x) memset(x,0,sizeof(x))
#define fillnum(x,n) fill(begin(x),end(x),n)
#define asort(x) sort(x.begin(),x.end())
#define dsort(x,t) sort(x.begin(),x.end(),greater<t>())

int main() {
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if(i % 2 == 1){
            cnt++;
        }
    }
    printf("%.10f\n",(double)((double)cnt / (double)N));
}