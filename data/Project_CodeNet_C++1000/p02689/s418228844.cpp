#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using vi = vector<int>;
using vsi = vector<set<int>>;

int main(void){
    int n, m;
    cin >> n >> m;
    vi H(n);
    for(int &h : H) cin >> h;
    vsi O(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a -= 1; b -= 1;
        O[a].insert(b);
        O[b].insert(a);
    }
    set<int> a;
    for(int i=0; i<n; i++){
        if(!O[i].empty()){
            bool frag = false;
            for(auto &v : O[i]){
                if(H[v] >= H[i]){
                    frag = true;
                    break;
                }
            }
            if(frag) continue;
        }
        a.insert(i);
    }
    cout << a.size() << '\n';
    return 0;
}