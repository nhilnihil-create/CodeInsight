#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector <int> a;
void insert(int t) {
    int k = a.size();
    a.push_back(t);
    while (k != 0 && a[(k - 1) / 2] < a[k]) {
        swap(a[k], a[(k - 1) / 2]);
        k = (k - 1) / 2;
    }
}
 

void maxheapify(int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l<(int)a.size() && a[l]>a[i]) {
        largest = l;
    }
    if (r<(int)a.size() && a[r]>a[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        maxheapify(largest);
    }
}

int extractmax() {
    int c;
    c = a[0];
    a[0] = a.back();
    a.pop_back();
    maxheapify(0);
    cout << c << endl;
}
int main() {
    string x;
    int y;
    while (cin >> x) {
        if (x == "end") {
            return 0;
        }
        else if (x == "insert") {
            cin >> y;
            insert(y);
        }
        else if (x=="extract"){
            extractmax();
        }
    }
}