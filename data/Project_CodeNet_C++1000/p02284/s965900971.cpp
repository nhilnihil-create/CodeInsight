#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1020
struct node
{
  int key;
  struct node *left, *right;
};
  
struct node T[MAX];

struct node *newNode(int item)
{
  struct node *temp =  (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
} 

void Preorder(struct node* root)
{
  

  if (root == NULL)
    return;
 

  printf(" ");
  printf("%d",root->key);
 
  Preorder(root->left); 
 
   
  Preorder(root->right);
} 

void inorder(struct node *root)
{
 

  if (root != NULL)
    {

      inorder(root->left);

      printf(" ");
      printf("%d", root->key);
     
      inorder(root->right);
    }
}
  

struct node* insert(struct node* node, int key)
{
    
  if (node == NULL) return newNode(key);
 
   
  if (key < node->key)
    node->left  = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);   
 
   
  return node;
}
  
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;
    
    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}


int main()
{
  int T[MAX];
  int z,n,i,j,a,hit;
  int count=0;
  char str[7];
  
  struct node *root = NULL;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%s",str);
    if(strcmp(str,"insert")==0){
      scanf("%d",&z);
      
      if(i==0)
	root = insert(root,z);
      else insert(root,z);}

    if(strcmp(str,"find")==0){
      scanf("%d",&a);
     
      if(search(root,a))
	
     printf("yes\n");
     
	else printf("no\n");
      }
 
    if(strcmp(str,"print")==0){
     
      inorder(root);
      printf("\n");
      Preorder(root);
      printf("\n");
    }}
  free(root);
  return 0;
}

