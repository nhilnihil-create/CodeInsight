#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    int H;
    int W;
    Shape(int H, int W) {
        this->H = H;
        this->W = W;
    }
};

int main(void) {
    int H, W;
    vector<Shape> shapeList;
    while(true) {
        cin >> H >> W;
        if((H == 0) && (W == 0)) break;
        shapeList.push_back(Shape(H, W));
    }

for(int s=0; s < shapeList.size(); s++) {
    for(int i=0; i < shapeList[s].H; i++) {
        for(int j=0; j < shapeList[s].W; j++) {
            cout << "#";
        }
        cout << endl;
    }
    cout << endl;
}

    return 0;
}