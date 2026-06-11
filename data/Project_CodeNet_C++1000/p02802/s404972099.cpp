#include <bits/stdc++.h>
using namespace std;

template <class T>
ostream &operator<<(ostream &out, vector<T> &A) {
    for(int i=0;i<(int)A.size();i++) out << A[i] << " ";
    return out;
}

struct problem {
    int pos;
    string result;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<problem> A(m);
    for (int i = 0; i < m; i++) {
        cin >> A[i].pos >> A[i].result;
        A[i].pos--;
    }
    vector<bool> vis(n, false);
	vector<int> penality(n, 0);
    int correct = 0, pen = 0;
    for (auto prob : A) {
        int prob_numb = prob.pos;
        string res = prob.result;
        if (vis[prob_numb]) continue;
        if (res == "AC") {
            vis[prob_numb] = true;
            correct++;
        } else {
            penality[prob_numb]++;
        }
    }
	// cout << penality << endl;
    for (int i=0;i<n;i++) {
		if(vis[i]){
			pen += penality[i];
			//cout << pen << " ok " << endl;
		}
	}
        cout << correct << " " << pen << endl;
    }
