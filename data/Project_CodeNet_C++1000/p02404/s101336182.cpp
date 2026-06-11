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
        if(H == 0 && W == 0) break;

        shapeList.push_back(Shape(H, W));
    }

    for(int i=0; i < shapeList.size(); i++) {
        for(int j=0; j < shapeList[i].H; j++) {
            for(int k=0; k < shapeList[i].W; k++) {
                if(j == 0 || j == shapeList[i].H - 1) {
                    cout << "#";
                } else {
                    if(k == 0 || k == shapeList[i].W - 1) {
                        cout << "#";
                    } else {
                        cout << ".";
                    }
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}