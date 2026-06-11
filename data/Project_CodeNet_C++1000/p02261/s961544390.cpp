#include <iostream>
#include <algorithm>

using namespace std;

struct Card
{
    char value;
    char suit;
};

void trace(Card A[], int n)
{
    cout << A[0].suit << A[0].value;
    for(int i=1; i < n; i++)
    {
        cout << " " << A[i].suit << A[i].value;
    }
    cout << endl;

    return;
}

bool isStable(Card C1[], Card C2[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(C1[i].suit != C2[i].suit)
            return false;
    }

    return true;
}

void bubbleSort(Card C[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = n-1; j >= i; j--)
        {
            if(C[j].value < C[j-1].value)
                swap(C[j], C[j-1]);
        }
    }

    return;
}

void selectionSort(Card C[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int minj = i;
        for(int j = i; j < n; j++)
        {
            if(C[j].value < C[minj].value)
                minj = j;
        }
        swap(C[i], C[minj]);
    }

    return;
}

int main(void)
{
    int n;
    Card C1[36], C2[36];

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> C1[i].suit >> C1[i].value;
    
    for(int i = 0; i < n; i++)
        C2[i] = C1[i];

    bubbleSort(C1, n);
    selectionSort(C2, n);

    trace(C1, n);
    cout << "Stable" << endl;

    trace(C2, n);
    if(isStable(C1, C2, n))
        cout << "Stable" << endl;
    else
        cout << "Not stable" << endl;
    
    return 0;
}