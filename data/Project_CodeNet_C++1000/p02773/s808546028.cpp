#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<tuple<int,string>> poll(n);
    vector<string> name(n);
    for(int i=0; i<n; i++){
        cin >> name.at(i);
    }
    sort(name.begin(), name.end());
    bool cand;
    int num=0;

    poll[0]=make_tuple(-1,name.at(0));
    for(int i=1; i<n; i++){
        if(name.at(i)==get<1>(poll[num])){
            get<0>(poll[num])--;
        }
        else{
            num++;
            poll[num]=make_tuple(-1,name.at(i));
        }
    }

    sort(poll.begin(), poll.end());

    int i=0;
    while(1){
        cout << get<1>(poll[i]) << endl;
        if(get<0>(poll[i])!=get<0>(poll[i+1])) break;
        i++;
    }
}