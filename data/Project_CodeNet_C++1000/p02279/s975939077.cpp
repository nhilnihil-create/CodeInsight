#include <cstdio>
using std::scanf;
using std::printf;

const int kNil = -1;

struct Node { int parent, left, right; };

void SetDepth(struct Node tree[], int cur_node, int cur_depth, int depth[]) {
  depth[cur_node] = cur_depth;
  if (tree[cur_node].left != kNil) {
    SetDepth(tree, tree[cur_node].left, cur_depth + 1, depth);
  }
  if (tree[cur_node].right != kNil) {
    SetDepth(tree, tree[cur_node].right, cur_depth, depth);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  // ??¨?????\???
  struct Node tree[n];
  for (int i = 0; i < n; ++i) {
    tree[i].parent = kNil;
    tree[i].left = kNil;
    tree[i].right = kNil;
  }
  for (int i = 0; i < n; ++i) {
    int id;
    scanf("%d", &id);

    int k;
    scanf("%d", &k);
    if (k == 0) {}
    if (k == 1) {
      int c;
      scanf("%d", &c);
      tree[id].left = c;
      tree[c].parent = id;
    }
    if (k >= 2) {
      int c1, c2;
      scanf("%d", &c1);
      tree[id].left = c1;
      tree[c1].parent = id;
      for (int j = 0; j < k - 1; ++j) {
        scanf("%d", &c2);
        tree[c1].right = c2;
        tree[c2].parent = id;
        c1 = c2;
      }
    }
  }

  // ??±????????????
  int root;
  for (int i = 0; i < n; ++i) {
    if (tree[i].parent == kNil) {
      root = i;
      break;
    }
  }
  int depth[n];
  SetDepth(tree, root, 0, depth);

  //?????????
  for (int i = 0; i < n; ++i) {
    int parent = tree[i].parent;
    int child = tree[i].left;

    printf("node %d: parent = %d, depth = %d, ", i, parent, depth[i]);

    if (parent == kNil) {
      printf("root, ");
    } else if (child == kNil) {
      printf("leaf, ");
    } else {
      printf("internal node, ");
    }

    // ??????????????????????????????
    printf("[");
    if (child != kNil) {
      printf("%d", child);
      while (tree[child].right != kNil) {
        child = tree[child].right;
        printf(", %d", child);
      }
    }
    printf("]\n");
  }

  return 0;
}