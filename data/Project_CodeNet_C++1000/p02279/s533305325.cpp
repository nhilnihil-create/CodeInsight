#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = s; i < n; i++)
#define rp(i,n) for (int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define all_acc(x) (x).begin(), (x).end(), 0LL
#define int long long
#define absSort(v) sort(a.begin(), a.end(), [](int i, int j) -> bool { return abs(i) < abs(j); });
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using ll = long long;
double pi=3.14159265359;

//出力するよ
void output(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        //if (i != 0)
        //    cout << " ";
        cout << s[i]<<endl;
    }
    //cout << endl;
}

void output3(vector<int> s){
    int n = s.size();
    for (int i = 0; i < n; i++){
        if (i != 0)
            cout << " ";
        cout << s[i];//<<endl;
    }
    cout << endl;
}
int MOD = pow(10, 9) + 7;

//出力形式を返す関数
string out(vector<int> v){
    string ans="[";
    for(int i=0;i<v.size();i++){
        if(i!=0) ans+=", ";
        ans+=to_string(v[i]);
    }
    ans+="]";
    return ans;
}

signed main() {
	int n; cin>>n;
    vector<vector<int>> child(n);
    vector<int> parent(n,-1);
    vector<int> depth(n,0);
    vector<string> status(n,"internal node");

    int root=0;

    for(int i=0;i<n;i++){
        int id,k; cin>>id>>k;
        for(int c=0;c<k;c++){
            int ci;cin>>ci;
            //子どもをリストに格納する
            child[id].push_back(ci);
            parent[ci]=id;
        }
        //葉の場合
        if(k==0){
            status[id]="leaf";
        }
    }


    for(int i=0;i<n;i++){
        if(parent[i]==-1){ 
            status[i]="root";
            root=i;
        }
    }
    //cout<<root<<endl;

    queue<int> search;
    search.push(root);
    //深さを求めるよ
    while(!search.empty()){
        //cout<<"おっぱい"<<endl;
        int node=search.front();
        search.pop();
        for(auto c:child[node]){
            depth[c]=depth[node]+1;
            search.push(c);
        }
    }

    for(int i=0;i<n;i++){
        if(parent[i]==-1) status[i]="root";
        string ans="node ";
        ans+=to_string(i)+": parent = "+to_string(parent[i])+", depth = ";
        ans+=to_string(depth[i])+", "+status[i]+", "+out(child[i]);
        cout<<ans<<endl;
    }

}
