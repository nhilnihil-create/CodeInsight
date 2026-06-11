#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
int main(){
        int x,y,a,b,c;
    cin >> x >> y >> a >> b >> c;
    vector<int64_t> p,q,r;
    for(int i=0;i<a;i++) {
        int64_t s;
        cin >> s;
        p.push_back(s);
    }
    for(int i=0;i<b;i++) {
        int64_t s;
        cin >> s;
        q.push_back(s);
    }
    for(int i=0;i<c;i++) {
        int64_t s;
        cin >> s;
        r.push_back(s);
    }

    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    sort(q.begin(),q.end());
    reverse(q.begin(),q.end());

    if(a!=x) for(int i=0;i<a-x;i++) p.pop_back();
    if(b!=y) for(int i=0;i<b-y;i++) q.pop_back();

    for(int i=0;i<q.size();i++) p.push_back(q.at(i));
    for(int i=0;i<r.size();i++) p.push_back(r.at(i));

    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());

    int64_t sum=0;
    for(int i=0;i<(x+y);i++) sum += p.at(i);

    cout << sum << endl;
}