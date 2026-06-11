#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<int> g[101010];
int h[101010];

int main(){
    int v, e;
    cin >> v >> e;
    
    for (int i = 0; i < e; i++){
        
        int s, t;
        cin >> s >> t;
        
        g[s].push_back(t);
        h[t]++;
    }
    
    // 入次数0の頂点の集合
    
    stack<int> st;
    
    //　入次数0の頂点を追加する
    for (int i = 0; i < v; i++) {
        if (h[i] == 0) st.push(i);
    }
    
    vector<int> ans;
    
    while (st.size()){
        
        int i = st.top();
        st.pop();
        
        ans.push_back(i);
        
        for (auto &j : g[i]){
            
            h[j]--;
            
            if (h[j] == 0) st.push(j);
        }
    }
    
    for (int i : ans) cout << i << endl;
}
