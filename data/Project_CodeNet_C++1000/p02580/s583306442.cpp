#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int h,w,m;
typedef pair<int,int> P;
//行与列
unordered_map<int,int> m1;
unordered_map<int,int> m2;
map<P,int> c;
int main() {
    vector<int> col,row;
    int ans = 0;
    int max1 = -1,max2 = -1;
    int index1,index2;
    cin >> h >> w >> m;
    
    int x,y = 0;
    for(int i = 0;i<m;i++){
        scanf("%d%d",&x,&y);
        if(!m1.count(x)){
            m1[x]= 1;
        }else{
            m1[x] += 1;
        }
        if(!m2.count(y)){
            m2[y] = 1;
        }else{
            m2[y] += 1;
        }
        max1 = max(max1,m1[x]);
        max2 = max(max2,m2[y]);
        c[make_pair(x,y)] = 1;
    }
    unordered_map <int,int>::iterator iter;
    for(iter = m1.begin(); iter != m1.end();iter++){
        if(iter->second == max1) row.push_back(iter->first);
    }
    for(iter = m2.begin(); iter != m2.end();iter++){
        if(iter->second == max2) col.push_back(iter->first);
    }
    // for(int i = 0;i<row.size();i++){
    //     cout << row[i] << " ";
    // }
    // cout << endl;
    for(int i = 0;i<row.size();i++){
        for(int j = 0;j<col.size();j++){
            int num;
            if(c[make_pair(row[i],col[j])] == 1) num = max1 + max2 -1;
            else num = max1 + max2;
            ans = max(ans,num);
            if(ans == max1 + max2) break;
        }
    }
    cout << ans << endl;

    
    return 0;
} 
