#include<iostream>
#include<vector>
#include<utility>
using namespace std;

void bubble_sort(vector<pair<char, int> >& c){
    bool flag = true;
    for (int i = c.size() - 1; flag; i--) {
        flag = false;
        for (int j = 0; j < i; j++) {
            if (c[j].second > c[j+1].second) {
                swap(c[j], c[j+1]);
                flag = true;
            }
        }
    }
}
void selection_sort(vector<pair<char, int> >& c) {
    for (int i = 0; i < c.size() - 1; i++) {
        int minj = i;
        for (int j = i + 1; j < c.size(); j++) {
            if (c[j].second < c[minj].second) minj = j;
        }
        if (i != minj) swap(c[i], c[minj]);
    }
}
bool is_same(vector<pair<char, int> >& c1, vector<pair<char, int> >& c2){
    for (int i = 0; i < c2.size(); i++) {
        if (c1[i].first != c2[i].first) return false;
    }
    return true;
}

int main(){
    int N;
    cin >> N;
    vector<pair<char, int> > card1(N);
    vector<pair<char, int> > card2(N);
    for (int i = 0; i < N; i++) {
        cin >> card1[i].first >> card1[i].second;
        card2[i].first  = card1[i].first;
        card2[i].second = card1[i].second;
    }
    bubble_sort(card1);
    for (int i = 0; i < N; i++) {
        cout << card1[i].first << card1[i].second << (i < N - 1 ? " " : "\n");
    }
    cout << "Stable" << endl;
    selection_sort(card2);
    for (int i = 0; i < N; i++) {
        cout << card2[i].first << card2[i].second << (i < N - 1 ? " " : "\n");
    }
    if (is_same(card1, card2)) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }


    return 0;
}