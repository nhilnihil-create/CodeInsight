#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

struct Card {
    char suit, value;
};

void print(struct Card A[], int num){
    for(int i=0; i<num; i++){
        if (i > 0) cout << " ";
        cout << A[i].suit << A[i].value;
    }
    cout << endl;
}

//book?????´??????1???true???0???false????????????

bool isStable(struct Card C1[], struct Card C2[], int num){
    for(int i=0; i<num; i++){
        if (C1[i].suit != C2[i].suit) return false;
    }
    return true;
}

void printArray(int A[], int num){
    for(int j=0; j<num; j++){
        if (j > 0) printf(" ");
        printf("%d", A[j]);
    }
    printf("\n");
}

int bubbleSort(struct Card A[], int num){
    int sw = 0;
    for(int i=0; i<num-1; i++){
        for(int j=num-1; j>=i+1; j--){
            if (A[j-1].value > A[j].value){
                swap(A[j-1], A[j]);
                sw++;
            }
        }
    }
    return sw;
}

int SelectionSort(struct Card A[], int num){
    int sw = 0;
    int minj;

    for(int i=0; i<num; i++){
        minj = i;
        for(int j=i; j<num; j++){
            if(A[j].value < A[minj].value){
                minj = j;
            }
        }
        swap(A[i], A[minj]);
        sw++;
    }
    return sw;
}

int main(){

    Card C1[100], C2[100];
    int num;
    char ch;

    cin >> num;
    for(int i=0; i<num; i++){
        cin >> C1[i].suit >> C1[i].value;
    }

    for(int i=0; i<num; i++) C2[i] = C1[i];

    bubbleSort(C1, num);
    SelectionSort(C2, num);

    print(C1, num);

    cout << "Stable" << endl;

    print(C2, num);

    if (isStable(C1, C2, num)) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }

    return 0;
}