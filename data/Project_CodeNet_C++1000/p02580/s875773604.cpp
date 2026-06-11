//
//  main.cpp
//  ABC176E
#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
int main(int argc, const char * argv[]) {
    int h,w,m;
    cin>>h>>w>>m;
    int hi,wi;
    vector<int> h_sum(h);
    vector<int> w_sum(w);
    set<P> st;
    rep(i,m){
        cin >>hi>>wi;
        hi--; wi--;
        h_sum.at(hi)++; // 行単位での爆破対象の数
        w_sum.at(wi)++; // 列単位での爆破対象の数
        st.emplace(hi,wi); // 爆破対象の場所を登録する
    }
    int mx_h=0;
    rep(i,h) mx_h=max(mx_h,h_sum.at(i));
    vector<int> h_lst; // 爆破対象の多い行のリスト
    rep(i,h) if(h_sum.at(i)==mx_h) h_lst.push_back(i);
    int mx_w=0;
    rep(j,w) mx_w=max(mx_w,w_sum.at(j));
    vector<int> w_lst; // 爆破対象の多い列のリスト
    rep(j,w) if(w_sum.at(j)==mx_w) w_lst.push_back(j);
    bool flag=false;
    rep(i,h_lst.size()) rep(j,w_lst.size()){
        // 爆破対象が　h_lst,w_lstの場所にあるか？　クロスしている場所にあるか？
        if(!st.count(make_pair(h_lst.at(i),w_lst.at(j)))){
            flag=true; // クロスしている場所にない　重複していない
            break;
        }
    }
    if(flag==true){
        cout<< mx_h+mx_w<<endl; // 重複していない場合
    } else {
        cout<<mx_h+mx_w-1<<endl; // 重複している場合
    }
    return 0;
}
