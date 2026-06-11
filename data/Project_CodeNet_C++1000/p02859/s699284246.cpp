// AtCoder template
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)

// merge-sort
// As we define n is the size of list, calculation will take O(nlogn) time.
template<typename T>
void m_sort(vector<T> &list){
    
    if(list.size() <= 1) return; // 終了条件

    int n = list.size();
    
    vector<T> m1,m2;
    for(int i = 0; i < n; ++i){
        if(i%2) m1.push_back(list[i]);
        else m2.push_back(list[i]);
    }
    
    m_sort(m1);
    m_sort(m2);

    for(int i = 0, m1_cnt = 0, m2_cnt = 0; i < n; ++i){
        if(m1_cnt == m1.size()) list[i] = m2[m2_cnt++];
        else if(m2_cnt == m2.size()) list[i] = m1[m1_cnt++];            
        else{
            if(m1[m1_cnt] < m2[m2_cnt]) list[i] = m1[m1_cnt++];
            else list[i] = m2[m2_cnt++];
        }
    }

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    
    vector<int> a(100000);
    rep(i,100000) a[i] = 100000-i;
    m_sort(a);

    int r; cin >> r;
    cout << r*r << endl;

}