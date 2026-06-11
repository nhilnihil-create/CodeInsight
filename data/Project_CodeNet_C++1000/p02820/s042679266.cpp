#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,k,r,s,p;
    cin >> n>> k >> r >> s >> p;
    string t;
    cin >> t;
    vector<char> hand;
    int point=0;
    for(int i=0; i<k; i++){
        if(t.at(i) == 'r'){
            hand.push_back('p');
            point += p;
        }
        else if(t.at(i) == 's'){
            hand.push_back('r');
            point += r;
        }
        else{
            hand.push_back('s');
            point += s;
        }
        //cout << point << endl;
    }
    for(int i=k; i<n; i++){
        if(t.at(i) == 'r'){
            if(hand.at(i-k) == 'p'){
                hand.push_back('n');
            }
            else{
                hand.push_back('p');
                point += p;
            }
        }
        else if(t.at(i) == 's'){
            if(hand.at(i-k) == 'r') hand.push_back('n');
            else{
                hand.push_back('r');
                point += r;
            }
        }
        else{
            if(hand.at(i-k) == 's') hand.push_back('k');
            else{
                hand.push_back('s');
                point += s;
            }
        }
        //cout << point << endl;
    } 
    cout << point << endl;
}
