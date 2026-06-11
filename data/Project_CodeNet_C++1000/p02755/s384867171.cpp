#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef map<string, int> msi;

int main(){
    int a,b; cin >> a >> b;
    int x_l = ceil(a / 0.08);
    int y_l = ceil(b / 0.1);
    int x_u = ceil((a+1) / 0.08);
    int y_u = ceil((b+1) / 0.1);
    vector<int> list1, list2;
    int i = x_l;
    while(i < x_u){
        list1.push_back(i);
        i++;
    }
    int j = y_l;
    while(j < y_u){
        list2.push_back(j);
        j++;
    }
    std::vector<int> list_inter; //list1とlist2の両方にある値 (積集合)
    std::set_intersection(list1.begin(), list1.end(), list2.begin(), list2.end(), std::back_inserter(list_inter));
    if(list_inter.empty()) cout << "-1" << endl;
    else cout << list_inter.at(0) << endl;
    return 0;
}
