#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <stack>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

void printVP(vector<pair<long long int,long long int>> vec_of_pairs);
void printV(vector<int> vec);
void printVVI(vector<vector<int>> vec);
void printMapSP(map<string,pair<int,int>> mp);
void printVC(vector<char> vec);
void printCurrMap(map<char,set<char>> mp);

int K, ans;
vi all_a;

bool can_get_height_with_less_cuts_than_k(int height){
    int tot_num_cuts = 0;
    for(int i=0;i<all_a.size();i++){
        int num_curr_cuts = ceil((all_a[i]*1.0)/height - 1);
        tot_num_cuts += num_curr_cuts;
//        cout<<num_curr_cuts<<" "<<height<<" "<<all_a[i]<<endl;
    }
//    cout<<"Total: "<<tot_num_cuts<<" "<<height<<endl;

    if(tot_num_cuts > K)
        return false;
    else
        return true;
}


//Inclusive of heights
void binary_search(int lower_height, int upper_height){
//    cout<<lower_height<<" "<<upper_height<<endl;

    if(upper_height - lower_height == 1) {
        if(can_get_height_with_less_cuts_than_k(lower_height))
            ans = lower_height;
        else
            ans = upper_height;

        return;
    }

    int mid = (upper_height + lower_height)/2;

    if(can_get_height_with_less_cuts_than_k(mid))
        // Then try do more cuts
        upper_height = mid;
    else
        lower_height = mid;

    binary_search(lower_height, upper_height);
}

void solve(){
    int N, Ai, max_Ai;
    cin>>N>>K;

    max_Ai = -1;

    for(int i=0;i<N;i++){
        cin>>Ai;
        all_a.push_back(Ai);
        if(Ai > max_Ai)
            max_Ai = Ai;
    }
  
  	if(max_Ai == 1){
        cout<<1<<endl;
        return;
    }

    binary_search(1, max_Ai);

    cout<<ans<<endl;
}

int main(){
    int t;
//    cin>>t;
    t = 1;
    for(int i=0;i<t;i++){
//        cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}
