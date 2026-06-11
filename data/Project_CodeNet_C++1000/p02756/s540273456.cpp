#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    string s;
    cin>>s;
    int nq;
    cin>>nq;
    int reverses = 0;
    deque<char> q;
    for(int i = 0; i < s.size(); i++)
    q.push_back(s[i]);
    while (nq--)
    {
        int t;
        cin>>t;
        if(t==1){
            reverses++;
        }else{
            int f;
            char c;
            cin>>f>>c;
            if(reverses%2){
                if(f == 1)
                f = 2;
                else
                {
                    f = 1;
                }
            }
            if(f == 1){
                q.push_front(c);
            }else
            {
                q.push_back(c);
            }
        }
    }
    if(reverses%2){
        for(auto it = q.rbegin(); it < q.rend(); it++){
            cout<<*it;
        }
        return 0;
    }else
    {
        for(auto it = q.begin(); it < q.end(); it++){
            cout<<*it;
        }
    }
    
    return 0;
}