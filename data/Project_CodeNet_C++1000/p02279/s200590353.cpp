#include <cstdio>
#include <iostream>
using namespace std;

static const int MAX_NUM = 100000;
static const int NOELEM  = -1;

struct stNode {
    int parent;
    int left;
    int right;
};

int main(void)
{
    int i, j;
    int key;
    int nums;
    int num;
    int sun;
    stNode elem[MAX_NUM];
    stNode *pNode;

    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        elem[i].parent = NOELEM;
        elem[i].left   = NOELEM;
        elem[i].right  = NOELEM;
    }
    for (i = 0; i < num; i++) {
        scanf("%d %d", &key, &nums);

        for (j = 0; j < nums; j++) {
            scanf("%d", &sun);
            if (j == 0) {
                elem[key].left = sun;
            }
            else {
                pNode->right = sun;
            }
            pNode = elem + sun;
            pNode->parent = key;
        }
    }

    for (i = 0; i < num; i++) {
        printf("node %d: parent = %d, ", i, elem[i].parent, i);
        nums = 0;
        key = elem[i].parent;
        while (key != NOELEM) {
            ++nums;
            key = elem[key].parent;
        }
        printf("depth = %d, ", nums);

        if (elem[i].parent == NOELEM) {
            printf("root, ");
        }
        else if (elem[i].left == NOELEM) {
            printf("leaf, ");
        }
        else {
            printf("internal node, ");
        }
        printf("[");
        key = elem[i].left;
        if (key != NOELEM) {
            printf("%d", key);
            key = elem[key].right;
            while (key != NOELEM) {
                printf(", %d", key);
                key = elem[key].right;
            }
        }
        printf("]\n");
    }

    return 0;
}