#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define repr(i,x,n) for(int i=(x);i<(n);i++)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

int main(){
    
    int n,slime_num;
    cin >> n;
    slime_num = 1 << n;
    vi s(slime_num),tree,temptree;
    rep(i,slime_num)cin >> s[i];

    sort(s.begin(),s.end());

    int index=slime_num-1;
    
    tree.push_back(s[index]);
    s[index] = -1;
    index--;
 
    rep(i,n){
        temptree = tree;
        sort(temptree.begin(),temptree.end());
        index = slime_num - 1;
        while(temptree.size() > 0 && index >= 0){
            if(s[index] == -1){
                index--;
                continue;
            }
            if(s[index] < temptree.back()){
                tree.push_back(s[index]);
                temptree.pop_back();
                s[index] = -1;
            }
            index--;
        }
        if(temptree.size() > 0){
            cout << "No" << endl;
            return 0;
        }
    }
 
    cout << "Yes" << endl;
 
    return 0;
}