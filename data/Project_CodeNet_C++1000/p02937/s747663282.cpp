#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 1000100
//#define NIL -1

int main() {
    string s;
    string t;
    vector<vector<LL>> idx_list(26);
    int tmp_num;
    LL idx=0;
    LL ans=0;

    cin >> s;
    cin >> t;

    for(int i=0; i<s.size(); i++){
        tmp_num = s[i] - 'a';
        idx_list[tmp_num].push_back(i);
    }

    for(int i=0; i<t.size(); i++){
        tmp_num = t[i] - 'a';
        int cand_idx=-1;
        if(idx_list[tmp_num].size()==0){
            ans=-2;
            break;
        }
        auto itr = lower_bound(idx_list[tmp_num].begin(), idx_list[tmp_num].end(), idx+1);
        if(i==0){
            itr = lower_bound(idx_list[tmp_num].begin(), idx_list[tmp_num].end(), idx);                
        }
        if(itr!=idx_list[tmp_num].end()){
            int dist = distance(idx_list[tmp_num].begin(), itr);
            //cout << "dist " << idx_list[tmp_num][dist] << endl; 
            ans=ans+idx_list[tmp_num][dist]-idx;
            idx=idx_list[tmp_num][dist];
        }else{
            ans=ans+idx_list[tmp_num][0]+s.size()-idx;
            idx=idx_list[tmp_num][0];
        }
        //cout << ans << " " << idx << endl;
    }
    ans++;

    cout << ans << endl;

    return 0;
}