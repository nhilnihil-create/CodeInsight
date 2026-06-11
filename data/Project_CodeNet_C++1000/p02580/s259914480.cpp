#include<iostream>
#include<stdio.h>
#include<string>
#include<stack>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int H,W,M;
    cin >> H;
    cin >> W;
    cin >> M;
    map<pair<int,int>,int> C;
    map<int,int> x_var;
    map<int,int> y_var;
    for(int i=0;i<M;i++){
        int x,y;
        cin >> x;
        cin >> y;
        x_var[x-1]++;
        y_var[y-1]++;
        C[make_pair(x-1,y-1)]++;
    }
    vector<int> x_vec(H);
    vector<int> y_vec(W);
    map<int,int> :: iterator it;
    int max_x=0;
    int max_y=0;
    for(it=x_var.begin();it!=x_var.end();it++){
        if(it->second > max_x){
            max_x=it->second;
            x_vec.clear();
            x_vec.push_back(it->first);
        }
        else if(it->second == max_x){
            x_vec.push_back(it->first);
        }
    }
    for(it=y_var.begin();it!=y_var.end();it++){
        if(it->second > max_y){
            max_y=it->second;
            y_vec.clear();
            y_vec.push_back(it->first);
        }
        else if(it->second == max_y){
            y_vec.push_back(it->first);
        }
    }
    int total=max_x+max_y-1;
    for(int i=0;i<x_vec.size();i++){
        for(int j=0;j<y_vec.size();j++){
            if(C[make_pair(x_vec[i],y_vec[j])] == 0){
                cout << total+1 << endl;
                return 0;
            }
        }
    }
    cout << total << endl;
    return 0;
}