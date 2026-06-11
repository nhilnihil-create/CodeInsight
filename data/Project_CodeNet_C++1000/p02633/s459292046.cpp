#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define inf 100000000000000000
#define mod 1000000007
#define MAX 300005
#define pb push_back
#define mp make_pair
#define vit vector<int>::iterator
typedef pair<lint,lint> pii;
lint A[MAX];
map<lint,lint> M;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    lint n,sum=0;
    cin>>n;
    lint pos=1;
    while(1){
        if(!((360*pos)%n)){
            cout<<(360*pos)/n;
            return 0;
        }
        pos++;
    }
    return 0;
}

