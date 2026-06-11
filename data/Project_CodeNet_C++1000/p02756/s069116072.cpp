#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <deque>
using namespace std;

string S; int Q;
void input()
{
    cin>>S>>Q;
}

void solve()
{
    deque<char> data;
    for(int i=0;i<S.length();++i){
        data.push_back(S[i]);
    }
    int rev_count=0;
    for(int i=0;i<Q;++i){
        int t; cin>>t;
        if(t==1) rev_count++;
        else if(t==2){
            int f; char c; cin>>f>>c;
            if((rev_count%2==1 && f==1)||(rev_count%2==0 && f==2)) data.push_back(c);
            else if((rev_count%2==1 && f==2)||(rev_count%2==0 && f==1)) data.push_front(c);
        }
    }
    if(rev_count%2==1) reverse(data.begin(),data.end());
    for(auto itr = data.begin(); itr != data.end(); ++itr) {
        cout<<*itr;
    }
    cout<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}