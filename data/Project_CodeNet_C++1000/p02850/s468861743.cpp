#include <bits/stdc++.h>
using namespace std;
long n;
vector <long> a;
vector <long> b;
vector <vector<long>> node;
vector <long> colorNumber;
long rootIndex = 0;
long depth = 0;
void dfs(long index){
    //cout << index;
    long rootColor = 0;
    if(index!=rootIndex){
        rootColor = colorNumber[index];
    }
    depth++;
    long tmp = 0;
    for(long i = 0; i < node[index].size(); i++){
        tmp++;
        if(tmp==rootColor){
            //cout << "rootColor: " << rootColor << endl; 
            tmp++;
        }
        //cout << tmp << " ";
        colorNumber[node[index][i]]=tmp;
    }
    //cout << endl;
    for(long i = 0; i < node[index].size(); i++){
        dfs(node[index][i]);
        depth--;
    }
    //cout << endl;
}
int main(){
    cin >> n;
    a = vector<long>(n);
    b = vector<long>(n);
    node = vector<vector<long>>(n);
    colorNumber = vector<long>(n,0);
    vector <long> pairent;
    vector <long> child;
    for(long i = 0; i < n-1; i++){
        cin >> a[i];
        cin >> b[i];
        a[i]--;
        b[i]--;
        node[a[i]].push_back(b[i]);
        pairent.push_back(a[i]);
        child.push_back(b[i]);
    }
    sort(pairent.begin(),pairent.end());
    pairent.erase(unique(pairent.begin(),pairent.end()),pairent.end());
    sort(child.begin(),child.end());
    child.erase(unique(child.begin(),child.end()),child.end());
    for(int i = 0; i < pairent.size(); i++){
        bool isFound = false;
        for(int j = 0; j < child.size(); j++){
            if(pairent[i]==child[j]){
                isFound=true;
                break;
            }
        }
        if(isFound==false){
            rootIndex=pairent[i];
        }
    }

    dfs(rootIndex);
    depth--;
    // cout << colorNumber[b[0]] << endl;
    // cout << colorNumber[b[1]] << endl;
    // cout << colorNumber[b[2]] << endl;
    // cout << colorNumber[b[3]] << endl;

    long ans = 0;
    for(int i = 0; i < n; i++){
        ans=max(ans,colorNumber[i]);
    }
    cout << ans << endl;
    for(long i = 0; i < n-1; i++){
        cout << colorNumber[b[i]] << endl;;
    }
    return 0;
}