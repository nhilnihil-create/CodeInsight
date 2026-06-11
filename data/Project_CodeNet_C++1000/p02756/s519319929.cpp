#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string S;
    ll Q;
    cin >>  S >> Q;

    string head = "";
    string tail = "";
    int re = 0;

    for (ll i = 0; i < Q ; i++)
    {
        int command1;cin >> command1;
        if(command1==2){
            int f;char c;
            cin >> f >> c;
            if((re%2==0 && f==1)|(re%2==1 && f==2))head+=c;
            else tail+=c;
        }else{//re: number of reverse command
            re++;
        }
    }
    if(re%2==1){
        reverse(S.begin(),S.end());
        reverse(tail.begin(),tail.end());
        cout << tail + S + head;
    }else{
        reverse(head.begin(),head.end());
        cout << head + S + tail;
    }
}