#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,x,y;
    cin >> n >> x >> y;
    x--;
    y--;
    vector<vector<int>> dist(n,vector<int>(n, 0));
    /*
    for(int i=0; i<x; i++){
        for(int j=0; j<n; j++){
            if(j <= x + (y-x+1)/2){
                dist.at(i).at(j) = j-x;
            } 
            else{
                dist.at(i).at(j) = x+1+abs(j-y);
            }
        }
    }
    */
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int p1,p2,p3;
            p1 = abs(i-j);
            p2 = abs(i-x) + 1 + abs(y-j);
            p3 = abs(i-y) + 1 + abs(x-j);
            dist.at(i).at(j) = min(min(p1, p2), p3);
        }
    }
    vector<int> ans(n,0);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans.at(dist.at(i).at(j))++;
            //cout << dist.at(i).at(j);
        }
        //cout << endl;
    }
    for(int i=1; i<n; i++){
        cout << ans.at(i)/2 << endl;
    }
}
