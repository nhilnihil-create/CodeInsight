#include <bits/stdc++.h>
using namespace std;
void print_vec(vector<int> &vec){
    vector<int> cpvec = vec;
    for(int i=0;i<cpvec.size();i++){
        cout << cpvec.at(i);
    }
    cout << endl;
}
int main(){
    string S;
    cin >> S;
    queue<int> que;
    vector<int> sequence(S.size()+1,-1);
    //print_vec(sequence);
    for(int i=0;i<S.size();i++){//0の位置を探す.Sを走査
        if(i==0&&S.at(i)=='<'){
            que.push(i);
            sequence.at(i)=0;
        }
        if(i<S.size()-1&&S.at(i)=='>'&&S.at(i+1)=='<'){
            que.push(i+1);
            sequence.at(i+1)=0;
        }
        if(i==S.size()-1&&S.at(i)=='>'){
            que.push(i+1);
            sequence.at(i+1)=0;
        }
    }
    //print_vec(sequence);
    while(!que.empty()){
        //print_vec(sequence);
        int coodinate = que.front(); que.pop();
        if(coodinate-1>=0&&S.at(coodinate-1)=='>'){
            que.push(coodinate-1);
            sequence.at(coodinate-1) = sequence.at(coodinate) + 1;
        }
        if(coodinate<S.size()&&S.at(coodinate)=='<'){
            que.push(coodinate+1);
            sequence.at(coodinate+1) = sequence.at(coodinate) + 1;
        }
    }
    long long cnt = 0;
    for(int i=0;i<sequence.size();i++){
        cnt+=sequence.at(i);
    }
    cout << cnt << endl;
    return 0;
}