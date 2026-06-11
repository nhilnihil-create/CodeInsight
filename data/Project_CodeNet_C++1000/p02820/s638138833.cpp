#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int r, s, p;
    cin >> r >> s >> p;
    string t; 
    cin >> t;
    int ans = 0;
    vector<char> hand;
    for(int i=0; i<k; i++) {
        if(t[i] == 'r') {hand.push_back('p'); ans += p;}
        else if(t[i] == 's') {hand.push_back('r'); ans += r;}
        else if(t[i] == 'p') {hand.push_back('s'); ans += s;}
        }
    for(int i=k; i<n; i++){
        if(t[i] == 'r'){
            if(hand[i-k] == 'p') hand.push_back('#');
            else {hand.push_back('p'); ans += p;}
        } 
        else if(t[i] == 's'){
            if(hand[i-k] == 'r') hand.push_back('#');
            else {hand.push_back('r'); ans += r;}
        } 
        else if(t[i] == 'p'){
            if(hand[i-k] == 's') hand.push_back('#');
            else {hand.push_back('s'); ans += s;}
        }
    }

    cout << ans << endl;
    return 0;

}