#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define MAX 100000
#define NIL -1

struct Node
{
    int parent, left, right;
};

Node T[MAX];

int depth(int i)
{
    int count = 0;
    int c = i;
    while (T[c].parent != NIL)
    {
        c = T[c].parent;
        count++;
    }
    return count;
}

string nodeType(int i)
{
    if (T[i].parent == NIL)
    {
        return "root";
    }
    else if (T[i].left == NIL)
    {
        return "leaf";
    }
    else
    {
        return "internal node";
    }
}

void printNodeChild(int i)
{
    int c = T[i].left;

    while(c != NIL)
    {
        cout << c;
        c = T[c].right;

        if (c != NIL)
        {
            cout << ", ";
        }
    }
}

void printNodeInfo(int i)
{
    cout << "node " << i << ": ";
    cout << "parent = " << T[i].parent << ",";
    cout << " depth = " << depth(i) << ",";
    cout << " " << nodeType(i) << ",";
    cout << " [";
    printNodeChild(i);
    cout << "]";

    cout << endl;
}

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        T[i].parent = T[i].left = T[i].right = NIL;
    }

    for (int i = 0; i < n; i++)
    {
        int id, k, l;

        cin >> id >> k;

        for (int j = 0; j < k; j++)
        {
            int c;
            cin >> c;
            if (j == 0)
            {
                T[id].left = c;
            }
            else
            {
                T[l].right = c;
            }
            l = c;
            T[c].parent = id;
        }
    }

    int root = 0;

    for (int i = 0; i < n; i++)
    {
        if (T[i].parent == NIL)
        {
            root = i;
        }
    }

   for (int i = 0; i < n; i++)
    {
        printNodeInfo(i);
    }

    //cout << root << endl;

    return 0;
}

