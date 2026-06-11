#include <bits/stdc++.h>
using namespace std;
int ans=0;
int n;
vector <vector<int>> x;
vector <vector<int>> y;
vector <bool> isHornestV;
bool isConflict(int x1, int x2){
    int x1SaidToX2 = -1;
    int x2SaidToX1 = -1;
    int x1SaidHimself = -1;
    int x2SaidHimself = -1;
    vector <int> x1Claim(n,-1);
    vector <int> x2Claim(n,-1);
    for(int i = 0; i < x[x1].size(); i++){
        if(x[x1][i]==x1){
            x1SaidHimself=y[x1][i];
        }
        if(x[x1][i]==x2){
            x1SaidToX2 = y[x1][i];
        }
        x1Claim[x[x1][i]]=y[x1][i];
    }
    //x2 claim  
    for(int i = 0; i < x[x2].size(); i++){
        if(x[x2][i]==x2){
            x2SaidHimself=y[x2][i];
        }
        if(x[x2][i]==x1){
            x2SaidToX1 = y[x2][i];
        }
        x2Claim[x[x2][i]]=y[x2][i];
    }
    if(isHornestV[x1]&&isHornestV[x2]){
        if(x1SaidHimself==0){
            return true;
        }
        if(x1SaidHimself==0){
            return true;
        }
        if(x1SaidToX2==0)return true;
        if(x2SaidToX1==0)return true;
        for(int i = 0; i < n; i++){
            if(x1Claim[i]==-1)continue;
            if(x2Claim[i]==-1)continue;
            if(x1Claim[i]!=x2Claim[i])return true;
        }
    }else if(isHornestV[x1]){
        if(x1SaidHimself==0){
            return true;
        }
        if(x1SaidToX2==1){
            return true;
        }
    }else if(isHornestV[x2]){
        if(x1SaidHimself==0){
            return true;
        }
        if(x2SaidToX1==1){
            return true;
        }
    }else{
        return false;
    }
    return false;
}
int checkHornestNum(){
    #if 0
    for(int i = 0; i < n; i++){
        if(isHornestV[i]){
            cout<<"h";
        }else{
            cout <<"-";
        }
    }
    cout << endl;
    #endif
    for(int i = 0; i < n; i++){
        for(int j = (i+1); j < n; j++){
            if(isConflict(i,j)){
                //cout << "conflict" << endl;
                return 0;
            }
        }
    }
    int ret = 0;
    for(int i = 0; i < n; i++){
        if(isHornestV[i]){
            ret++;
        }
    }
    return ret;
}
void dfs(bool isHornest){
    isHornestV.push_back(isHornest);
    if(isHornestV.size()==n){
        ans = max(ans,checkHornestNum());
        return;
    }
    dfs(true);
    isHornestV.pop_back();
    dfs(false);
    isHornestV.pop_back();
}
int main(){
    cin >> n;
    vector <int> a(n);
    x =vector <vector<int>> (n);
    y =vector <vector<int>> (n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        x[i]=vector<int>(a[i]);
        y[i]=vector<int>(a[i]);
        for(int j = 0; j < a[i]; j++){
            cin >> x[i][j] >>  y[i][j];
            x[i][j]--;
        }

    }
    dfs(true);
    isHornestV.pop_back();
    dfs(false);
    isHornestV.pop_back();
    cout << ans << endl;
    #if 0
    cout << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < a[i]; j++){
            cout << x[i][j] << " " << y[i][j] << endl;
        }
    }

    #endif
    return 0;
}