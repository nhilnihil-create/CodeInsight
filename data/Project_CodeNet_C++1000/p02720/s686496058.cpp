#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    std::deque<string> num;
    std::deque<string> lunlun;
    for (int i=1;i<10;i++) {
        num.emplace_back(to_string(i));
    }
    int count=0;
    while (1) {
        count++;
        string tmp=num.front();
        num.pop_front();
        lunlun.emplace_back(tmp);
        int hoge=tmp[tmp.size()-1]-'0';
        if (hoge!=0) {
            string tmp_diff=tmp+to_string(hoge-1);
            num.emplace_back(tmp_diff);
        }
        string tmp_same=tmp+to_string(hoge);
        num.emplace_back(tmp_same);
        if (hoge!=9) {
            string tmp_plus=tmp+to_string(hoge+1);
            num.emplace_back(tmp_plus);
        }
        if (count==n) {
            cout<<lunlun[n-1]<<endl;
            break;
        }
    }
}