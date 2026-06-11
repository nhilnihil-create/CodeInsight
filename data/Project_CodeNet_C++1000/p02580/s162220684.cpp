//(・ω・)
#include <stdio.h>
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, atoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <iomanip> //setprecision
#include <limits>
#include <sstream> //istringstream
#include <stdlib.h>
#include <list>
#include <iterator>//std::advance()
using namespace std;
int main(){
    int H, W, m;
    cin >> H >> W >> m;
    vector<int> h(m);
    vector<int> w(m);
    set<pair<int,int>> b;
    for(int i=0; i<m; i++){
        cin >> h[i] >> w[i];
        b.insert(make_pair(h[i],w[i]));
    }
    sort(h.begin(),h.end());
    sort(w.begin(),w.end());
    vector<pair<int,int>> hcount;
    vector<pair<int,int>> wcount;
    int wc=1,hc=1;
    for(int i=0; i<m-1; i++){
        if(w[i]==w[i+1]) wc++;
        else{
            wcount.push_back(make_pair(wc,w[i]));
            wc=1;
        }
        if(h[i]==h[i+1]) hc++;
        else{
            hcount.push_back(make_pair(hc,h[i]));
            hc=1;
        }
    }
    wcount.push_back(make_pair(wc,w[m-1]));
    hcount.push_back(make_pair(hc,h[m-1]));
    sort(hcount.begin(),hcount.end(),greater<pair<long long ,long long >>());
    sort(wcount.begin(),wcount.end(),greater<pair<long long ,long long >>());
    int I=hcount[0].first,max=hcount[0].first+wcount[0].first-b.count(make_pair(hcount[0].second,wcount[0].second));
    bool fin=0;
    for(auto& i:hcount){
        if(I>i.first) break;
        int J=wcount[0].first;
        for(auto& j:wcount){
            if(J>j.first) break;
            int x;
            x=i.first+j.first-b.count(make_pair(i.second,j.second));
            if(x>max){
                max=x;
                fin=1;
                break;
            }
            else if(max>x){
                fin=1;
                break;
            }
            J=j.first;
        }
        if(fin) break;
    }
    cout << max << endl;
}
