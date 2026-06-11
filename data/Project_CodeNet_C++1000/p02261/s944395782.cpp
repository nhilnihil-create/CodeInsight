#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define INF 2000000000

using namespace std;

int main()
{   
    int n;
    cin >> n;

    vector<pair<char, int>> card1(n);
    vector<pair<char, int>> card2(n);

    char mark;    int num;  
    REP(i, n) {
        cin >> mark >> num;
        card1[i] = make_pair(mark, num);
        card2[i] = make_pair(mark, num);
    }

    for (int i = 0; i < n; i++) {
        for (int j = n-1; j > i; j--) {
            if (card1[j].second < card1[j-1].second) {
                card1[j].swap(card1[j-1]);
            }
        }
    }

    REP(i, n) {
        if (i != 0)  cout << " ";
        cout << card1[i].first << card1[i].second;
    }

    cout << endl << "Stable" << endl;

    for (int i = 0; i < n; i++) {
        int mini = INF;
        int j_tmp;

        for (int j = i; j < n; j++) {
            if (mini > card2[j].second) {
                mini = card2[j].second;
                j_tmp = j;
            }
        }

        card2[i].swap(card2[j_tmp]);
    }

    REP(i, n) {
        if (i != 0)  cout << " ";
        cout << card2[i].first << card2[i].second;
    }

    if (card1 == card2)
        cout << endl << "Stable" << endl;
    
    else
        cout << endl << "Not stable" << endl;
}
