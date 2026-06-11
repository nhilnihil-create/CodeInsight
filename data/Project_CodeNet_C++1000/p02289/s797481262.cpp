#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> v;
    void maxHeapify(int i){
        int left,right,largest;
        left = 2 * (i + 1) - 1;
        right = 2 * (i + 1);
        largest = i;
        if (left < v.size() && v[left] > v[largest]){
            largest = left;
        }
        if (right < v.size() && v[right] > v[largest]){
            largest = right;
        }

        if (largest != i){
            swap(v[i],v[largest]);
            maxHeapify(largest);
        }
    }

public:
    Heap(const vector<int> &heap) : v(heap) {
        for (int i = (v.size() - 1) / 2; i >= 0; --i) maxHeapify(i);
    }

    void print(){
        for (auto item : v) cout << " "  << item;
        cout << endl;
    }

    int extract(){
        if (v.empty())return -1;
        int result = v.front();
        v.front() = v.back();
        v.pop_back();
        if (v.empty())return -1;
        maxHeapify(0);
        return result;
    }

    void insert(int value){
        v.push_back(value);
        int i = v.size() - 1;
        while(i > 0 && v[i] > v[(i-1)/ 2]){
            int p = (i - 1) / 2;
            swap(v[i],v[p]);
            i = p;
        }
    }
};


int main(){
    //freopen("in", "r", stdin);
    Heap h(vector<int>(0));
    for (;;) {
        int num;
        string command;
        cin >> command;
        if (command == "insert") {
            cin >> num;
            h.insert(num);
        } else if (command == "extract") {
            cout << h.extract() << endl;
        } else {
            break;
        }
    }
    return 0;
}