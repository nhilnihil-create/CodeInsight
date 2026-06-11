#include<iostream>
using namespace std;
static const int N = 100;
struct Card{
    char suit,value;
};

void trace(struct Card A[], int n){
    for(int i = 0; i < n; i++){
        if(i > 0) cout << " ";
        cout << A[i].suit << A[i].value;
    }
    cout << endl;
}
void BubbleSort(struct Card A[], int n){
    int i,j;
    for(i = 0; i < n; i++){
        for(j = n-1; j >= i; j--){
            if(A[j].value < A[j-1].value){
                Card t = A[j];
                A[j] = A[j-1];
                A[j-1] = t;
            }
        }
    }
}
void SelectionSort(struct Card A[], int n){
    int i,j,minj;
    for(i = 0; i < n; i++){
        minj = i;
        for(j = i; j < n; j++){
            if(A[j].value < A[minj].value){
                minj = j;
            }
        }
        Card t = A[i];
        A[i] = A[minj];
        A[minj] = t;
    }
}
bool isStable(struct Card A1[], struct Card A2[], int n){
    for(int i = 0; i < n; i++){
        if(A1[i].suit != A2[i].suit) return false;
    }
    return true;
}
int main(){
    int n;
    Card C1[N], C2[N];
    char ch;

    cin >> n;    
    for(int i = 0; i < n; i++) 
        cin >> C1[i].suit >> C1[i].value;
    for(int i = 0; i < n; i++)
        C2[i] = C1[i];
    
    BubbleSort(C1,n);
    SelectionSort(C2,n);

    trace(C1, n);
    cout << "Stable" << endl;
    trace(C2, n);
    if( isStable(C1, C2, n) ){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }
}